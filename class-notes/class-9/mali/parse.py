from subprocess import Popen, PIPE, STDOUT

file = open("out.txt", "r")
content = file.read()

content = content \
            .replace("What is the capital of ", "") \
            .replace("Actually, it's ", "") \
            .replace("...\n", "|") \
            .replace("?\n", "|")

country_capital = dict()

cSplit = content.split("|")

for i in range(0, len(cSplit) - 1):
    if(i%2 == 0):
        if cSplit[i] in country_capital:
            continue
        else:
            country_capital[cSplit[i]] = cSplit[i + 1]


p = Popen("nc ec2-18-216-96-228.us-east-2.compute.amazonaws.com 8000", stdout=PIPE, stdin=PIPE, shell=True)

while(p.poll() is None):
    country = p.stdout.readline().replace("What is the capital of ", "").replace("?\n", "")
    capital = country_capital[country] + '\n'
    # output = p.communicate(input=capital)[0]
    # print(output)


# print(p.stdout.readline())