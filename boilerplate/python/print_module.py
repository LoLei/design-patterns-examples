print('[print_module.py] Begin execution')
print('[print_module.py] __name__ is:', __name__)

def fancy_module_function():
    print('[print_module.py] Running fancy module function')

if __name__ == '__main__':
    import sys
    if len(sys.argv) == 2 and sys.argv[1] == 'fancy':
        fancy_module_function()

print('[print_module.py] End execution')
