#!/Usr/bin/python

import os
import sys
import urllib
import re
import time

OK  = 0
ERR = 1

def getCurFileDir():
    path = sys.path[0]
    if os.path.isdir(path):
        return path
    elif os.path.isfile(path):
        return os.path.dirname(path)    

def getLocalDir():
    thisMonthDir = getCurFileDir() + "/" + time.strftime('%Y%m')
    if not os.path.exists(thisMonthDir):
        os.mkdir(thisMonthDir)

    localDir = thisMonthDir + "/" + time.strftime('%Y%m%d') + ".jpg"
    return localDir

def getImaegUrl(pageUrl):
    page = urllib.urlopen(pageUrl).read()
    item = re.search('<div.*?class="download_link".*?a href="(.*?)">(.*?)</div>', page)
    if item == None:
        return ERR, None

    url = re.search('http://.*?.jpg', item.group())
    if url == None:
        return ERR, None

    return OK, url.group()


def convertImage(filePath):
    os.system("convert.im6 -resize 1280x " + filePath + " " + filePath)
    
def setWallPaper(filePath):
    os.system("xfconf-query -c xfce4-desktop -p /backdrop/screen0/monitor0/image-path -s " + filePath)
    os.system("xfconf-query -c xfce4-desktop -p /backdrop/screen0/monitor0/image-style -s " + str(1))
    
# URL_NG_TODAY = "http://photography.nationalgeographic.com/photography/photo-of-the-day/alligator-okefenokee-swamp-farlow/"
# URL_NG_TODAY = "http://photography.nationalgeographic.com/photography/photo-of-the-day/lions-pride-serengeti-nichols/"
URL_NG_TODAY = "http://photography.nationalgeographic.com/photography/photo-of-the-day/"
LOCAL_FILE   = getLocalDir()

if os.path.exists(LOCAL_FILE):
    print "Just one, no more."
    exit(0)

print "Game start!"
ret, url = getImaegUrl(URL_NG_TODAY)
if ret != OK:
    print "I am sorry."
    exit(0)

print " ** 3 **"
urllib.urlretrieve(url, LOCAL_FILE)
print " ** 2 **"
convertImage(LOCAL_FILE)
print " ** 1 **"
setWallPaper(LOCAL_FILE)

print " ** Done! **"
