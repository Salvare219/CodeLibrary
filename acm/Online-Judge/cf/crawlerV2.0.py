# coding = utf-8
import re
import os
import lxml
import time
import json
import urllib
import urllib2
import cookielib
import HTMLParser
from bs4 import BeautifulSoup 


username = 'X'

coachname = 'X'
password = 'X'

login_url = 'http://codeforces.com/enter'
api_url = 'http://codeforces.com/api/user.status?handle=' + username + '&from=1&count=10000'
code_url = 'http://codeforces.com/X/submission/'


headers = {
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Accept-Language':'zh-CN,zh;q=0.8,en;q=0.6,ja;q=0.4',
'Cache-Control':'max-age=0',
'Connection':'keep-alive',
'Host':'codeforces.com',
'Upgrade-Insecure-Requests':'1',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

data = {
'csrf_token':'',
'action':'enter',
'handle':username,
'password':password}

data2 = {
'csrf_token':'',
'action':'toggleShowUnofficial',
'showUnofficial':'on'}


def get_csrftoken(html):
    return re.search("name='csrf_token' value='(\w+)'", html).group(1)

def get_cookie(opener, login_url):
    try:
        response = opener.open(urllib2.Request(login_url, headers = headers))
        result = response.read()
    except urllib2.URLError, e:
        print 'Error occurred on getting csrf_token\n' + login_url
        exit()
    data['csrf_token'] = get_csrftoken(result)
    post_data = urllib.urlencode(data)
    try:
        response = opener.open(urllib2.Request(login_url, post_data, headers = headers))
    except urllib2.URLError, e:
        print 'Can\'t login\n' + login_url
        exit()

def get_codelist(opener):
    codelist = []
    response = opener.open(api_url)
    result = response.read()
    content = json.loads(result)
    if content['status'] == 'FAILED':
        print content['comment']
        exit()
    # print json.dumps(content, encoding='utf-8', ensure_ascii=False, indent=1)
    for item in content['result']:
        if item['verdict'] == 'OK':
            codelist.append([item['contestId'], item['id'], item['programmingLanguage'], item['problem']['index']])
    return codelist

def get_code(opener, url):
    try:
        response = opener.open(urllib2.Request(url, headers = headers))
        result = response.read()
    except urllib2.URLError, e:
        if hasattr(e, 'reason'):
            print e.reason
        if hasattr(e, 'code'):
            print e.code
        print code_url
        exit()
    return re.search(r'style="padding: 0.5em;">([\d\D]+?)</pre>', result).group(1)

def generate_filename(contestId, index, language):
    if ~language.find('GNU'):
        suffix = '.cpp'
    elif ~language.find('Python'):
        suffix = '.py'
    elif ~language.find('Java'):
        suffix = '.java'
    elif ~language.find('Ruby'):
        suffix = '.rb'
    else:
        print language
        exit()
    return 'code\\' + str(contestId) + str(index) + suffix


def main():
    #init
    print 'Initing...'
    cookie = cookielib.CookieJar()
    handler=urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)
    
    #get cookie
    print 'Logining...'
    get_cookie(opener, login_url)
    print 'Login successful!'

    #get codelist
    print 'Crawling accepted code list of ' + username + '...'
    codelist = get_codelist(opener)
    tot = len(codelist)
    print 'There are ' + str(tot) + ' AC code in total'

    #get source code
    now = 0
    val = 0
    for item in codelist:
        contestId = item[0]
        submissionId = item[1]
        language = item[2]
        index = item[3]
        now += 1
        print contestId, submissionId

        ###########chinese#############
        if [contestId, submissionId] == [100341, 8065039]:
            continue
        if [contestId, submissionId] == [100186, 7255946]:
            continue 
        if [contestId, submissionId] == [409, 6226264]:
            continue 
        ###########chinese#############

        #process filename
        filename = generate_filename(contestId, index, language)

        if not os.path.exists(filename):
            time.sleep(0.5)
            val += 1
            #process codeurl
            submission_url = code_url.replace('X', ('gym/' if contestId > 100000 else 'contest/') + str(contestId)) + str(submissionId)

            #get source code
            code = get_code(opener, submission_url)
            code = HTMLParser.HTMLParser().unescape(code)

            #save source code
            codefile = open(filename, 'w')
            codefile.write(code)
            codefile.close()
        print 'Complete ' + str(now) + '/' + str(tot) + '...'
    print 'All sources are crawled!'

if __name__ == '__main__':
    main()

