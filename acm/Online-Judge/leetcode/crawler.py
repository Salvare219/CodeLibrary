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
password = 'X'


login_url = 'https://leetcode.com/accounts/login/'
list_url = 'https://leetcode.com/submissions/'
code_url = 'https://leetcode.com/submissions/detail/'


headers = {
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Accept-Language':'zh-CN,zh;q=0.8,en;q=0.6,ja;q=0.4',
'Cache-Control':'max-age=0',
'Connection':'keep-alive',
'Host':'leetcode.com',
'Referer':'https://leetcode.com/',
'Upgrade-Insecure-Requests':'1',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

data = {
'csrfmiddlewaretoken':'',
'login':username,
'password':password}



def get_csrftoken(html):
    return re.search("name='csrfmiddlewaretoken' value='(.+)'", html).group(1)

def get_cookie(opener, login_url):
    try:
        response = opener.open(urllib2.Request(login_url, headers = headers))
        result = response.read()
    except urllib2.URLError, e:
        print 'Error occurred on getting csrfmiddlewaretoken\n' + login_url
        exit()

    data['csrfmiddlewaretoken'] = get_csrftoken(result)
    post_data = urllib.urlencode(data)
    try:
        response = opener.open(urllib2.Request(login_url, post_data, headers = headers))
    except urllib2.URLError, e:
        if hasattr(e, 'reason'):
            print e.reason
        if hasattr(e, 'code'):
            print e.code
        print 'Can\'t login\n' + login_url
        exit()

def get_codelist(opener, url):
    time.sleep(1)
    codelist = []
    response = opener.open(url)
    result = response.read()
    return re.findall('href="/problems/(.+)/"[\d\D]+?href="/submissions/detail/(\d+)/"><strong>Accepted[\d\D]+?<td>[\d\D]+?<td>(.+)</td>', result)

def get_code(opener, url):
    while True:
        try:
            response = opener.open(urllib2.Request(url, headers = headers), timeout = 10)
            break
        except:
            print 'timeout...'
            continue
    result = response.read()
    return re.findall("submissionCode: '(.+)',[\d\D]+editCodeUrl", result)[0]

def generate_filename(problemName, language):
    if ~language.find('mysql'):
        suffix = '.mysql'
    elif ~language.find('cpp'):
        suffix = '.cpp'
    elif ~language.find('python'):
        suffix = '.py'
    elif ~language.find('java'):
        suffix = '.java'
    else:
        print language
        exit()
    return 'code\\' + problemName + suffix


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

    page = 35
    tot = 0
    while page <= 57:
        #get codelist
        print 'Crawling accepted code list of page ' + str(page) + '...'
        codelist = get_codelist(opener, list_url + str(page))
        cnt = len(codelist)
        tot += cnt
        print 'There are ' + str(cnt) + ' AC code in this page.'

        #get source code
        now = 0
        val = 0
        for item in codelist:
            problemName = item[0]
            submissionId = item[1]
            language = item[2]
            now += 1
            print submissionId

            #process filename
            filename = generate_filename(problemName, language)

            if not os.path.exists(filename):
                time.sleep(1)
                val += 1
                #process codeurl
                submission_url = code_url + submissionId

                #get source code
                code = get_code(opener, submission_url)
                code = code.decode('unicode-escape')

                #save source code
                codefile = open(filename, 'w')
                codefile.write(code)
                codefile.close()
            print 'Complete ' + str(now) + '/' + str(cnt) + '...'

        page += 1

    print 'All sources are crawled!'
    print 'There are ' + str(val) + ' after duplicate!'

if __name__ == '__main__':
    main()

