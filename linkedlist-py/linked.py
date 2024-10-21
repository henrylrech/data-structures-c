from util import printInfo

class Flight:
    def __init__(self, flight_code: str, airport_code: str, datetime: str):
        self.code = flight_code
        self.airport = airport_code
        self.datetime = datetime
        self.queue = LinkedList()

class Person:
    def __init__(self, name, cellphone, address):
        self.name = name
        self.cellphone = cellphone
        self.address = address

class FlightNode:
    def __init__(self, data: Flight):
        self.data: Flight | None = data
        self.next: FlightNode | None = None

class PersonNode:
    def __init__(self, data: Person):
        self.data: Person | None = data
        self.next: PersonNode | None = None

class LinkedList:
    def __init__(self):
        self.head: FlightNode | PersonNode = None

    def insertNewFlight(self, flight_code: str, airport_code: str, datetime: str):
        flight = Flight(flight_code, airport_code, datetime)
        new_node = FlightNode(flight)
        if self.head is None:
            printInfo(f'inserido novo voo ordenadamente: {flight.code}')
            self.head = new_node
            return
        
        # Caso o início seja menor que o cod atual
        elif self.head.data.code >= new_node.data.code:
            new_node.next = self.head
            self.head = new_node

        else:
            aux = self.head

            # Percorre a linked list para achar a posição correta
            while aux.next and new_node.data.code > aux.next.data.code:
                aux = aux.next

            new_node.next = aux.next
            aux.next = new_node

        printInfo(f'inserido novo voo ordenadamente: {flight.code}')

    def _findFlight(self, flight_code: str) -> Flight | None:
        aux = self.head
        
        while(aux != None and aux.data.code != flight_code):
            aux = aux.next

        if aux == None:
            return None
        else:
            return aux.data
        
    def queuePerson(self, flight_code, name, cellphone, address):
        person = Person(name, cellphone, address)
        new_node = PersonNode(person)

        flight = self._findFlight(flight_code)
        if flight is None:
            return
        
        if flight.queue.head is None:
            flight.queue.head = new_node
            printInfo(f'enfileirado pessoa: {person.name} no voo: {flight_code}')
            return
        else:
            new_node.next = flight.queue.head
            flight.queue.head = new_node

        printInfo(f'enfileirado pessoa: {person.name} no voo: {flight_code}')

    def dequeuePerson(self, flight_code: str):
        flight = self._findFlight(flight_code)

        if flight is None:
            return

        if flight.queue.head is None:
            return

        aux = flight.queue.head
        while(aux != None and aux.next.next != None):
            aux = aux.next

        printInfo(f'desenfileirado pessoa: {aux.next.data.name} no voo: {flight_code}')
        aux.next = None

    def removeFlight(self, flight_code: str):
        aux = self.head
  
        if aux == None:
            print("Nenhum voo disponível.")
            return

        # se for o primeiro, remove
        if aux.data.code == flight_code:
            if(self.head == None):
                return

            self.head = self.head.next
            printInfo(f'removido voo: {flight_code}')
            return

        # percorre a linkedlist
        while(aux != None and aux.next.data.code != flight_code):
            aux = aux.next

        if aux == None:
            printInfo(f'Não foi encontrado voo com codigo {flight_code}')
            return
        else:
            printInfo(f'removido voo: {flight_code}')
            aux.next = aux.next.next

    def getLength(self) -> int:
        aux = self.head
        cont = 0

        while aux != None:
            aux = aux.next
            cont = cont + 1

        return cont
    
    def printFlightNames(self) -> bool:
        aux = self.head

        if aux == None:
            printInfo(f'Não foi encontrado voo')
            return False
        
        res = "Voos: "
        while aux != None:
            res = res + aux.data.code + ", "
            aux = aux.next

        print(res[:-2])
        return True

    def printAirportCodes(self) -> bool:
        aux = self.head
        
        if aux == None:
            printInfo(f'Não foi encontrado voo')
            return False

        res = "Aeroportos: "
        while aux != None:
            res = res + aux.data.airport + ", "
            aux = aux.next

        print(res[:-2])
        return True

    def printFlights(self, flight_code=None):
        aux = self.head
        if (flight_code == None):
            print('Lista de voos: ')

        while(aux):
            if (flight_code == None or flight_code == aux.data.code):
                print(f"Código do voo: {aux.data.code}, Código do aeroporto: {aux.data.airport}, Data: {aux.data.datetime}, Quantidade de passageiros: {aux.data.queue.getLength()}")
            aux = aux.next

    def printQueue(self, flight_code):
        flight = self._findFlight(flight_code)
        if flight is None:
            return

        aux = flight.queue.head
        print(f'Fila do voo: {flight_code}')
        while(aux):
            print(f"Nome: {aux.data.name}, Telefone: {aux.data.cellphone}, Endereço: {aux.data.address}")
            aux = aux.next

    def biggestQueue(self):
        aux = self.head

        data = ""
        num = 0
        while(aux):
            cur = aux.data.queue.getLength()
            if cur > num:
                data = aux.data.code
                num = cur
            aux = aux.next

        if data == "":
            print("Nenhum voo possui passageiros")
        else:
            print(f"O voo com mais passageiros é o voo ({data}), que possui {num} passageiro(s)")
    
    def printFlightsEmptyQueue(self):
        aux = self.head

        data = ""
        while(aux):
            if aux.data.queue.getLength() == 0:
                data = data + aux.data.code + ", "
            aux = aux.next

        print("Voos sem passageiros: " + data[:-2])

    def printAllQueues(self):
        aux = self.head
        while(aux):
            self.printQueue(aux.data.code)
            aux = aux.next
            
    def printFlightsAirport(self, airport_code):
        aux = self.head
        while(aux):
            if (aux.data.airport == airport_code):
                self.printFlights(aux.data.code)
            aux = aux.next
