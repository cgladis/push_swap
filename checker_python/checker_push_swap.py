import math
import os
import random
import sys

# command_list = []

# ==================================

def sa(stack_a):
    stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
    # command_list.append("sa")

def sb(stack_b):
    stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
    # command_list.append("sb")

def ss(stack_a, stack_b):
    sa(stack_a)
    sb(stack_b)
    # command_list.append("ss")

def pa(stack_a, stack_b):
    stack_a.insert(0, stack_b.pop(0))
    # command_list.append("pa")

def pb(stack_a, stack_b):
    stack_b.insert(0, stack_a.pop(0))
    # command_list.append("pb")

def ra(stack_a):
    stack_a.append(stack_a.pop(0))
    # command_list.append("ra")

def rb(stack_b):
    stack_b.append(stack_b.pop(0))
    # command_list.append("rb")

def rr(stack_a, stack_b):
    ra(stack_a)
    rb(stack_b)
    # command_list.append("rr")

def rra(stack_a):
    stack_a.insert(0, stack_a.pop())
    # command_list.append("rra")

def rrb(stack_b):
    stack_b.insert(0, stack_b.pop())
    # command_list.append("rrb")

def rrr(stack_a, stack_b):
    rra(stack_a)
    rrb(stack_b)
    # command_list.append("rrr")

def run_command(command, stack_a, stack_b):
    if command == "sa":
        sa(stack_a)
    if command == "sb":
        sb(stack_b)
    if command == "ss":
        ss(stack_a, stack_b)
    if command == "pa":
        pa(stack_a, stack_b)
    if command == "pb":
        pb(stack_a, stack_b)
    if command == "ra":
        ra(stack_a)
    if command == "rb":
        rb(stack_b)
    if command == "rr":
        rr(stack_a, stack_b)
    if command == "rra":
        rra(stack_a)
    if command == "rrb":
        rrb(stack_b)
    if command == "rrr":
        rrr(stack_a, stack_b)
    # print(stack_a, "a: ", command, " b: ", stack_b)

#========================================

def check_command_list(command_list, stack_a):
    stack_b = []
    for command in command_list:
        run_command(command, stack_a, stack_b)
    # print(stack_a)
    if stack_a == sorted(stack_a):
        return (stack_a, '\033[32mOk\033[0m', 1)
    else:
        return (stack_a, "\033[31mError\033[0m", 0)


if len(sys.argv) != 2:
    exit(0)
file_name = sys.argv[1]
log_data = []
r1 = int(input("from = "))
r2 = int(input("to = "))
n = int(input("number retry = "))
for i in range(r1, r2 + 1):
    good_result = int(i * math.log2(i))
    for j in range(1, n + 1):
        stack_a = []
        # stack_a = [1, 3, -5, -3, 4]
        x = random.randrange(-r2, r2, 1)
        stack_a.append(x)
        for z in range(1, i):
            x = random.randrange(-r2, r2, 1)
            while (x in stack_a):
                x = random.randrange(-r2, r2, 1)
            stack_a.append(x)
        # print(stack_a)
        argv = []
        argv.append(file_name)
        for item in stack_a:
            argv.append(str(item))
        fd = os.pipe()
        pid = os.fork()
        if (pid == 0):
            os.dup2(fd[1], 1)
            os.execvp(file_name, argv)
        os.close(fd[1])
        os.dup2(fd[0], 0)
        os.close(fd[0])
        # print("test")
        os.wait()
        res = sys.stdin.readlines()
        command_list = []
        for item in res:
            command_list.append(item.strip("\n"))
        length = len(command_list)
        result, res, success = check_command_list(command_list, stack_a.copy())
        if not success:
            print(i, "\t", j, "\t | ", stack_a, "\t", command_list, "\t", result, "\t", res)
            log_data.append('ERROR \tnumber of items:{0}\ttest #{1}\t| {2}\t{3}\t{4}\n'.format(i, j, stack_a, command_list, result))
        else:
            if (length <= good_result):
                print("number of items: ", i, "\t test #", j, "\t | count: \033[32m", length, "/", good_result, "\033[0m\t", res)
            elif (length <= good_result * 1.2):
                print("number of items: ", i, "\t test #", j, "\t | count: \033[33m", length, "/", good_result, "\033[0m\t", res)
                log_data.append('NOT GOOD\tnumber of items:{0}\ttest #{1}\t| {2}\t{3}\t{4}\n'.format(i, j, stack_a, command_list, result))
            else:
                print("number of items: ", i, "\t test #", j, "\t | count: \033[31m", length, "/", good_result, "\033[0m\t", res)
                log_data.append('BAD     \tnumber of items:{0}\ttest #{1}\t| {2}\t{3}\t{4}\n'.format(i, j, stack_a, command_list, result))
        log_file = open("log.txt", "w")
        log_file.writelines(log_data)
        log_file.close()
