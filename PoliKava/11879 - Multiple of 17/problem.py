from __future__ import print_function
from sys import stdin, stdout, stderr

def debug(*args, **kwargs):
    print(*args, file=stderr, **kwargs)

def main():

	n = int(stdin.readline())

	for case in range(n):

		n1, n2 = stdin.readline().split()

		n1 = int(n1[::-1])
		n2 = int(n2[::-1])

		stdout.write("%d\n" % int(str(n1+n2)[::-1]))

if __name__ == "__main__":
	main()