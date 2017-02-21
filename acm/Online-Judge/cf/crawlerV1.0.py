# coding = utf-8
import re
import os
import lxml
import time
import urllib
import urllib2
import cookielib
from bs4 import BeautifulSoup 



url = 'http://codeforces.com/submissions/salvare001/page/'
code_url = 'http://codeforces.com'


headers = {
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
'Accept-Language':'zh-CN,zh;q=0.8,en;q=0.6,ja;q=0.4',
'Cache-Control':'max-age=0',
'Connection':'keep-alive',
'Host':'codeforces.com',
'Upgrade-Insecure-Requests':'1',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'}

data = {
}


def main():
    #get cookie
    cookie = cookielib.CookieJar()
    handler=urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)
    post_data = urllib.urlencode(data)
    response = opener.open(urllib2.Request(url + '1#', headers = headers))


    #process html
    next = 1
    cnt = 0
    tot = 0

    while True:
        #get html
        cnt += 1

        print 'processing page ' + str(cnt) + ' ...'

        try:
            response = opener.open(urllib2.Request(url + str(next), headers = headers))
            result = response.read()
        except urllib2.URLError, e:
            if hasattr(e, 'reason'):
                print e.reason
            if hasattr(e, 'code'):
                print e.code
            print url + str(next)
            return 0

        code_list = []
        ac_list = re.findall(r'submissionId="(\d+)" submissionVerdict="OK"', result)
        change = 0
        for item in ac_list:
            code_list.append(re.search(r'/contest/\d+/submission/' + item, result).group())

        find = re.findall(r'page/' + str(next + 1), result)
        if find:
            next += 1
        else:
            next = -1
        
        print 'there are ' + str(len(code_list)) + ' code in this page'

        for item in code_list:
            time.sleep(0.5)
            contest_num = re.search(r'contest/(\d+)', item).group(1)
            try:
                response = opener.open(urllib2.Request(code_url + item, headers = headers))
                result = response.read()
            except urllib2.URLError, e:
                if hasattr(e, 'reason'):
                    print e.reason
                if hasattr(e, 'code'):
                    print e.code
                print code_url + item
                return 0

            filename = 'code\\' + contest_num + re.search(r'/contest/' + contest_num + '/problem/(.)', result).group(1) + '.cpp'
            code = re.search(r'style="padding: 0.5em;">([\d\D]+?)</pre>', result).group(1)

            if not os.path.exists(filename):
                tot += 1
                open(filename, 'w').write(code)

        if next == -1:
            break

        print 'page ' + str(cnt) + ' has successed!'

    print str(tot) + ' files in total!'


if __name__ == '__main__':
    main()

