from linked import LinkedList
from menu import Menu
import util
import sys

def main():
    linkedlist = LinkedList()

    if (len(sys.argv) > 1 and sys.argv[1] == '--info'):
        print('Info mode is ON!')
        util.infomode = True

    Menu(linkedlist)

if __name__ == "__main__":
    main()
