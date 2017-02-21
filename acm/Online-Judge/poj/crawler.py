# coding = utf-8
import re
import os
import lxml
import time
import urllib
import urllib2
import cookielib
from bs4 import BeautifulSoup 


username = 'X'
password = 'X'

url = 'http://poj.org/status?user_id=' + username + '&result=0&top='
login_url = 'http://poj.org/login'
code_url = 'http://poj.org/showsource?solution_id='

headers = {
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Cache-Control':'max-age=0',
'Connection':'keep-alive',
'Content-Length':'53',
'Content-Type':'application/x-www-form-urlencoded',
'Host':'poj.org',
'Origin':'http://poj.org',
'Referer':'http://poj.org/',
'Upgrade-Insecure-Requests':'1',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36}'}

data = {
'user_id1':username,
'password1':password,
'B1':'login',
'url':'/'}


def main():
    #get cookie
    cookie = cookielib.CookieJar()
    handler=urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)
    post_data = urllib.urlencode(data)
    opener.open(urllib2.Request(login_url, post_data, headers))


    #process html
    pattern1 = re.compile(r'solution_id=(\d+)')
    pattern2 = re.compile(r'top=(\d+)><font color=blue>Next Page')
    pattern3 = re.compile(r'problem\?id=(\d+)')
    pattern4 = re.compile(r'monospace">([\d\D]*)</pre>')
    next = '-1'
    cnt = 0
    tot = 0

    while True:
        #get html
        time.sleep(0.5);
        cnt += 1
        try:
            response = opener.open(urllib2.Request(url+next))
            result = response.read()
        except urllib2.URLError:
            print url+next

        code_list = re.findall(pattern1, result)
        size = len(code_list)
        next = re.findall(pattern2, result)[0]

        print 'page ' + str(cnt) + ' has ' + str(size) + 'files.'
        
        for item in code_list:
            time.sleep(0.5)
            try:
                response = opener.open(code_url + item)
                result = response.read()
            except urllib2.URLError:
                print code_url + item

            filename = 'code\\' + 'poj' + re.findall(pattern3, result)[0] + '.cpp'
            code = re.findall(pattern4, result)

            if not os.path.exists(filename):
                tot += 1
                open(filename, 'w').write(code[0])

        if size < 20:
            break

        print 'page ' + str(cnt) + ' has successed!'

    print str(tot) + ' files in total!'


if __name__ == '__main__':
    main()

