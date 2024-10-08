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

    # if (len(sys.argv) > 1 and sys.argv[1] == '--info'):
    #     print('Info mode is ON!')
    #     util.infomode = True

    # # 1) Incluir voo na lista de voos, mantendo a lista ordenada pelo código do voo
    # linkedlist.insertNewFlight('POACHI', 'POA', '01/01/2001 15:00:00')
    # linkedlist.insertNewFlight('POARUS', 'POA', '01/01/2005 16:00:00')
    # linkedlist.insertNewFlight('POAFRA', 'POA', '01/01/2008 19:00:00')

    # # 2) Remover voo da lista de voos. Quando um voo é removido, sua fila de espera também é removida
    # linkedlist.removeFlight('POAFRA')

    # # 3) Consultar voos: escrever na tela os voos cadastrados, e a quantidade de passageiros na fila de espera de cada voo
    # linkedlist.printFlights()

    # # 4) Enfileirar passageiro na fila de espera de um voo
    # linkedlist.queuePerson('POACHI', 'João', '88887777', 'Rua Imaginária, 123')
    # linkedlist.queuePerson('POACHI', 'Pedro', '88889999', 'Rua Fictícea, 321')
    # linkedlist.queuePerson('POACHI', 'Camila', '12345678', 'Rua Especial, 420')
    # linkedlist.printQueue('POACHI')

    # # 5) Desenfileirar passageiro da fila de espera de um voo
    # linkedlist.dequeuePerson('POACHI')
    # linkedlist.printQueue('POACHI')

    # # 6) Consultar fila de espera: exibir os nomes dos passageiros que estão na fila de espera de um voo (do início para o fim)
    # linkedlist.printQueue('POACHI')

if __name__ == "__main__":
    main()
