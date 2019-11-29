import print_module

print('[print_my_program.py] Begin execution')
print('[print_my_program.py] __name__ is:', __name__)

def main():
    print('[print_my_program.py] Running main function')
    print_module.fancy_module_function()

if __name__ == '__main__':
    main()

print('[print_my_program.py] End execution')
