def fancy_module_function():
    print('[module.py] Running fancy module function')

if __name__ == '__main__':
    import sys
    if len(sys.argv) == 2 and sys.argv[1] == 'fancy':
        fancy_module_function()
