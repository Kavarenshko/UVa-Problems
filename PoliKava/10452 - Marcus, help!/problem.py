from __future__ import print_function
import sys

m = []
ok_string = "IEHOVA@#"
end_pos = [0,0]
a = b = 0

def debug(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def walk(r,c):
	global m, ok_string, end_pos, b

	#debug("Pos: %d %d" % (r,c))

	if r < 0 or m[r][c] not in ok_string:
		return ""
	m[r][c] = 'B'

	if list((r,c)) == end_pos:
		return " "

	res = walk(r-1,c)
	if res:
		return "forth %s" % res

	if c > 0:
		res = walk(r, c-1)
		if res:
			return "left %s" % res

	if (c < b-1):
		res = walk(r, c+1)
		if res:
			return "right %s" % res

	return ""

def main():

	global m, a, b

	TC = int(input())
	for tc in range(TC):
		m = []
		a,b = map(int, input().split())
		for row in range(a):
			s = list(input())
			m.append(s)
		#print(m)
		end_pos[1] = m[0].index("#")
		print ("%s" % walk(a-1,m[a-1].index("@"))[:-2])

if __name__ == "__main__":
	main()