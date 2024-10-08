from linked import LinkedList

def Menu(linkedlist: LinkedList):
    x = -1
    while x != "0":
        print("-"*25)
        print("Menu Principal")
        print("1 - Incluir voo")
        print("2 - Remover voo")
        print("3 - Consultar voos")
        print("4 - Adicionar passageiro a fila de espera")
        print("5 - Desenfileirar passageiro")
        print("6 - Consultar fila de espera")
        print("7 - Voo com maior fila de espera")
        print("8 - Voos sem fila de espera")
        print("9 - Consultar um único voo")
        print("10 - Listar todas as filas")
        print("0 - Sair")
        print("-"*25)

        x = input()

        if (x == "1"): # Incluir voo
            codfli = input("Digite o código do voo: \n")
            codaer = input("Digite o código do aeroporto: \n")
            dt = input("Digite a data: (dd/mm/yyyy hh:mm:ss): \n")
            linkedlist.insertNewFlight(codfli, codaer, dt)

        elif (x == "2"): # Remover voo
            ok = linkedlist.printFlightNames()
            if (ok == False):
                print("Nenhum voo a ser removido.")
                continue
            cod = input("Digite o código do voo a ser removido: \n")
            linkedlist.removeFlight(cod)

        elif (x == "3"): # Consultar voos
            linkedlist.printFlights()

        elif (x == "4"): # Adicionar passageiro a fila de espera
            ok = linkedlist.printFlightNames()
            if (ok == False):
                print("Nenhum voo encontrado.")
                continue
            cod = input("Digite o código do voo que o passageiro entrará na fila: \n")
            name = input("Digite o nome do passageiro: \n")
            tel = input("Digite o telefone do passageiro: \n")
            end = input("Digite o endereço do passageiro: \n")
            linkedlist.queuePerson(cod, name, tel, end)

        elif (x == "5"): # Desenfileirar passageiro
            ok = linkedlist.printFlightNames()
            if (ok == False):
                print("Nenhum voo encontrado.")
                continue
            cod = input("Digite o código do voo para um passageiro ser desenfileirado: \n")
            linkedlist.dequeuePerson(cod)

        elif (x == "6"): # Consultar fila de espera
            ok = linkedlist.printFlightNames()
            if (ok == False):
                print("Nenhum voo encontrado.")
                continue
            cod = input("Digite o código do voo que deseja ver a fila de espera: \n")
            linkedlist.printQueue(cod)

        elif (x == "7"): # Voo com maior fila de espera
            linkedlist.biggestQueue()

        elif (x == "8"): # Voos sem fila de espera
            linkedlist.printFlightsEmptyQueue()

        elif (x == "9"): # Consultar um único voo
            ok = linkedlist.printFlightNames()
            if (ok == False):
                print("Nenhum voo encontrado.")
                continue
            cod = input("Digite o código do voo")
            linkedlist.printFlights(cod)
            linkedlist.printQueue(cod)

        elif (x == "10"): # Listar todas as filas
            linkedlist.printAllQueues()
            pass
