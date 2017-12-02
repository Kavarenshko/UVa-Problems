import sys

def main():
	l = list(map(int, sys.stdin.read().split()))
	for tc in range(int(len(l)/2)):
		a,b = l[2*tc], l[2*tc+1]
		print("%.0f" % b**(1.0/a))

if __name__ == "__main__":
	main()