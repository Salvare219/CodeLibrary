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

login_url = 'https://vjudge.net/user/login'
api_url = 'https://vjudge.net/user/submissions?username=' + username + '&status=AC&pageSize=500&maxId='
code_url = 'https://vjudge.net/solution/data/'


headers = {
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

data = {
'username':username,
'password':password}



def get_cookie(opener):
    post_data = urllib.urlencode(data)
    try:
        response = opener.open(urllib2.Request(login_url, post_data, headers = headers))
    except urllib2.URLError, e:
        print 'Can\'t login\n' + login_url
        exit()

def get_codelist(opener):
    codelist = []
    lastId = -1
    while True:
        time.sleep(1)
        next_url = api_url
        if lastId != -1:
            next_url += str(lastId - 1)
        response = opener.open(next_url)
        result = response.read()
        content = json.loads(result)
        for item in content['data']:
            codelist.append([item[0], item[2] + item[3], item[7].lower()])
        lastId = codelist[-1][0]
        if len(content['data']) < 500:
            break
    return codelist

def get_code(opener, url):
    while True:
        try:
            response = opener.open(urllib2.Request(url, headers = headers), timeout = 5)
            break
        except:
            print 'timeout...'
            time.sleep(1)
            print 'try again.'
            continue
    result = response.read()
    content = json.loads(result)
    return content['code']

def generate_filename(index, language):
    return 'code\\' + index + '.' + language


def main():
    #init
    print 'Initing...'
    cookie = cookielib.CookieJar()
    handler=urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)
    
    #get cookie
    print 'Logining...'
    get_cookie(opener)
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
        submissionId = item[0]
        index = item[1]
        language = item[2]
        now += 1
        print index, submissionId

        #process filename
        filename = generate_filename(index, language)

        if not os.path.exists(filename):
            time.sleep(2)
            val += 1
            #process codeurl
            submission_url = code_url + str(submissionId)

            #get source code
            code = get_code(opener, submission_url)

            #save source code
            codefile = open(filename, 'w')
            codefile.write(code.encode('utf'))
            codefile.close()
        print 'Complete ' + str(now) + '/' + str(tot) + '...'
    print 'All sources are crawled!'
    print 'There are ' + str(val) + ' AC code after duplicating'

if __name__ == '__main__':
    main()

