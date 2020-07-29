# ===========================================================================================================
# Example code that demonstrate how to use subprocess to start runnign an external application inside a
# Python code.
# ===========================================================================================================

import os
import subprocess

def main():
    devnull = open(os.devnull, 'w')
    n = [10,20,30,40,50]
    for i in range(len(n)):
        print("N = %d" % (n[i]))
        subprocess.call(["/home/berg/Github/Programming/Python/Subprocess/Cpp-App/main","%d" % (n[i])], stdout=devnull) # Suppresing output

if __name__ == "__main__":
    main()



