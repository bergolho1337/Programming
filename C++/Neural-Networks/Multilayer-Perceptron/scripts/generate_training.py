import sys
import random

def generate_training_set (n):
    counter_1 = 0
    counter_2 = 0
    counter_3 = 0
    counter_4 = 0
    file = open("training_set.txt","w")
    file.write("%u\n" % (n))
    for i in range(n):
        a = random.randint(0,1)
        b = random.randint(0,1)
        c = a ^ b
        file.write("%d %d %d\n" % (a,b,c))

        if (a == 0 and b == 0):
            counter_1 = counter_1 + 1
        if (a == 0 and b == 1):
            counter_2 = counter_2 + 1
        if (a == 1 and b == 0):
            counter_3 = counter_3 + 1
        if (a == 1 and b == 1):
            counter_4 = counter_4 + 1
    print("Counter 1 = %u" % counter_1)
    print("Counter 2 = %u" % counter_2)
    print("Counter 3 = %u" % counter_3)
    print("Counter 4 = %u" % counter_4)    
    file.close()


if (len(sys.argv) != 2):
    print("python %s <n>" % (sys.argv[0]))
    sys.exit(1)

n = int(sys.argv[1])
generate_training_set(n)