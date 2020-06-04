import random
import os

min_num = int(input("Enter min amount of numbers to test : "))
max_num = int(input("Enter max amount of numbers to test : "))
group_nums = int(input("Enter how many tests per group : "))

def join_elem_oflist(lst):
	result = ""
	for item in lst:
		result += item
		result += " "
	return result

f=open('random_prng.txt', 'w')
lines = 0
group = min_num
while group <= max_num:
	lines = 0
	while lines < group_nums:
		num = 0
		uniq_lst = []
		str_nums = ""
		while num < group:
			str_nums = str(random.randint(-4999, 5699))
			if str_nums not in uniq_lst:
				uniq_lst.append(str_nums)
				num += 1
		str_nums = join_elem_oflist(uniq_lst)
		# print(str_nums)
		f.write(str_nums)
		f.write("\n")
		lines += 1
	if group < 150:
		group += 1
	else:
		group += 10
f.close()

os.system("./test_script.sh random_prng.txt")
