import sys
import os
from random import randint

def Usage (pName):
    print("----------------------------------------------")
    print("Usage:> "+pName+" <nTemps>")
    print("<nTemps> = Number of temperatures reading")
    print("----------------------------------------------")
    

def genReadings (n):
    outFile = open("raw_temps.txt","w")
    nInt = int(n)
    for i in range(nInt):
        outFile.write(str(randint(0,23))+" "+str(randint(-273,273))+"\n")
    outFile.close()

def main():
    if (len(sys.argv) < 2):
        Usage(sys.argv[0])
    genReadings(sys.argv[1])

if __name__ == "__main__":
    main()