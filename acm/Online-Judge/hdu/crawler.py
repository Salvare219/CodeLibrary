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

url1 = 'http://acm.hdu.edu.cn/status.php?first='
next = 'X'
url2 = '&user=' + username + '&pid=&lang=&status=5'
login_url = 'http://acm.hdu.edu.cn/userloginex.php?action=login'
code_url = 'http://acm.hdu.edu.cn/viewcode.php?rid='

headers = {
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Accept-Language':'zh-CN,zh;q=0.8,en;q=0.6,ja;q=0.4',
'Cache-Control':'max-age=0',
'Connection':'keep-alive',
'Host':'acm.hdu.edu.cn',
'Upgrade-Insecure-Requests':'1',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

data = {
'username':username,
'userpass':password,
'login':'Sign In'}


def main():
    #get cookie
    cookie = cookielib.CookieJar()
    handler=urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)
    post_data = urllib.urlencode(data)
    response = opener.open(urllib2.Request(login_url, post_data, headers))


    #process html
    pattern1 = re.compile(r'rid=(\d+)')
    pattern2 = re.compile(r'first=(\d+)')
    pattern3 = re.compile(r'pid=(\d+)')
    pattern4 = re.compile(r'text-align:left;">([\d\D]*)</textarea>')
    cnt = 0
    tot = 0

    while True:
        #get html
        time.sleep(1);
        cnt += 1
        try:
            response = opener.open(urllib2.Request(url1 + next + url2, headers = headers))
            result = response.read()
        except urllib2.URLError, e:
            if hasattr(e, 'reason'):
                print e.reason
            if hasattr(e, 'code'):
                print e.code
            print url1 + next + url2
            return 0

        code_list = re.findall(pattern1, result)
        size = len(code_list)
        find = re.findall(pattern2, result)
        if find:
            next = find[0]
        else:
            next = ''

        print 'page ' + str(cnt) + ' has ' + str(size) + ' files.'
        
        for item in code_list:
            time.sleep(1)
            try:
                response = opener.open(urllib2.Request(code_url + item, headers = headers))
                result = response.read()
            except urllib2.URLError:
                print code_url + item
                return 0

            # print code_url + item
            # open('1.txt', 'w').write(result)
            # open('1.html', 'w').write(result)
            # return 0

            filename = 'code\\' + 'hdu' + re.findall(pattern3, result)[0] + '.cpp'
            code = re.findall(pattern4, result)

            if not os.path.exists(filename):
                tot += 1
                open(filename, 'w').write(code[0])

        if not next:
            break

        print 'page ' + str(cnt) + ' has successed!'

    print str(tot) + ' files in total!'


if __name__ == '__main__':
    main()

