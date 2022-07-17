import cgi, cgitb
from array_stack import ArrayStack
from array_queue import ArrayQueue
from name_number import NameNumber

cgitb.enable()

servers_stack = ArrayStack()
customers_queue = ArrayQueue()
stack_copy = ArrayStack()
queue_copy = ArrayQueue()


def open_for_evening(servers_stack, customers_queue):
    print("<tr align='center'><td>loaded server: {}</td></tr>".format(servers_stack.top().get_name()))
    print("<tr align='center'><td>loaded customer {}</td></tr>".format(customers_queue.first().get_name()))
    difference = 0
    while servers_stack.is_empty() != True and customers_queue.is_empty() != True:
        temp = 0
        if difference == 0:
            temp = servers_stack.top().get_number() - customers_queue.first().get_number()
        elif difference > 0:
            temp = difference - customers_queue.first().get_number()
        elif difference < 0:
            temp = difference + servers_stack.top().get_number()

        if temp == 0:
            amount = servers_stack.top().get_number()
            print("<tr align='center'><td>{} equally servers {} ({})</td></tr>"
                  .format(servers_stack.pop().get_name(), customers_queue.dequeue().get_name(),
                          amount))

            if len(servers_stack) >= 1:
                print("<tr align='center'><td>loaded server: {}</td></tr>"
                      .format(servers_stack.top().get_name()))

            if len(customers_queue) >= 1:
                print("<tr align='center'><td>loaded customer {}</td></tr>"
                      .format(customers_queue.first().get_name()))
        if temp > 0:
            amount = customers_queue.first().get_number()
            print("<tr align='center'><td>{} servers {} ({})</td></tr>"
                  .format(servers_stack.top().get_name(), customers_queue.dequeue().get_name(),
                          amount))

            servers_stack.top().set_number(abs(temp))

            if len(customers_queue) >= 1:
                print("<tr align='center'><td>loaded customer {}</td></tr>"
                      .format(customers_queue.first().get_name()))

        if temp < 0:
            amount = servers_stack.top().get_number()
            print("<tr align='center'><td>{} partially servers {} ({})</td></tr>".
                  format(servers_stack.pop().get_name(), customers_queue.first().get_name(),
                         amount))

            customers_queue.first().set_number(abs(temp))

            if len(servers_stack) >= 1:
                print("<tr align='center'><td>loaded server: {}</td></tr>"
                      .format(servers_stack.top().get_name()))

    if len(servers_stack) <= 1:
        print("<tr align='center'><td>No more Servers</td></tr>")
    if len(customers_queue) <= 1:
        print("<tr align='center'><td>No more Customers</td></tr>")


servers_item = servers.split("\n")
for item in servers_item:
    if item == "\r" or item == " \r" or item == "":
        pass
    else:
        Name_Number = NameNumber()
        (name, value) = item.split()
        Name_Number.set_name(name)
        Name_Number.set_number(int(value))
        servers_stack.push(Name_Number)
        stack_copy.push(Name_Number)

customers_item = customers.split("\n")
for item in customers_item:
    if item == "\r" or item == " \r" or item == "":
        pass
    else:
        Name_Number = NameNumber()
        (name, value) = item.split()
        Name_Number.set_name(name)
        Name_Number.set_number(int(value))
        customers_queue.enqueue(Name_Number)
        queue_copy.enqueue(Name_Number)

open_for_evening(servers_stack, customers_queue)


