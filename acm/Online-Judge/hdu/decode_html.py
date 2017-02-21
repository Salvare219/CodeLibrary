# coding = utf-8
import re
import os
import lxml
import time
import HTMLParser
import urllib
import urllib2
import cookielib
from bs4 import BeautifulSoup


def solve(name):
    code = open(name, 'r').read()
    os.remove(name)
    open('b_' + name, 'w').write(code)
    decode = HTMLParser.HTMLParser().unescape(code)
    open(name, 'w').write(decode)
    os.remove('b_' + name)

filename = os.listdir('.')
for item in filename:
    if os.path.isfile(item):
        print 'operating ' + item + ' ...'
        solve(item)
        
