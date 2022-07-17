#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

import cgi, cgitb
from array_stack import ArrayStack
from array_queue import ArrayQueue
from name_number import NameNumber

cgitb.enable()




def open_for_evening(servers_stack, customers_queue):
    print("<tr align='center'><td>loaded server: {}</td></tr>".format(servers_stack.top().get_name()))
    print("<tr align='center'><td>loaded customer {}</td></tr>".format(customers_queue.first().get_name()))

    while servers_stack.is_empty() != True and customers_queue.is_empty() != True:

        temp = servers_stack.top().get_number() - customers_queue.first().get_number()

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
            temp = 0

        if temp > 0:
            amount = customers_queue.first().get_number()
            print("<tr align='center'><td>{} servers {} ({})</td></tr>"
                  .format(servers_stack.top().get_name(), customers_queue.dequeue().get_name(),
                          amount))

            servers_stack.top().set_number(abs(temp))

            if len(customers_queue) >= 1:
                print("<tr align='center'><td>loaded customer {}</td></tr>"
                      .format(customers_queue.first().get_name()))
            temp = 0

        if temp < 0:
            amount = servers_stack.top().get_number()
            print("<tr align='center'><td>{} partially servers {} ({})</td></tr>".
                  format(servers_stack.pop().get_name(), customers_queue.first().get_name(),
                         amount))

            customers_queue.first().set_number(abs(temp))

            if len(servers_stack) >= 1:
                print("<tr align='center'><td>loaded server: {}</td></tr>"
                      .format(servers_stack.top().get_name()))
            temp = 0

    if len(servers_stack) <= 1:
        print("<tr align='center'><td>No more Servers</td></tr>")
    if len(customers_queue) <= 1:
        print("<tr align='center'><td>No more Customers</td></tr>")


def reverse(stack):
    temp = ArrayStack()
    while not stack.is_empty():
        temp.push(stack.pop())
    return temp


print("Content-type: text/html\n")
aform = cgi.FieldStorage()
servers = aform.getvalue('Servers')
customers = aform.getvalue('Customers')
submit = aform.getvalue('submit')

servers_stack = ArrayStack()
customers_queue = ArrayQueue()
stack_copy = ArrayStack()
queue_copy = ArrayQueue()

if submit == "Open for the evening":
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

    stack_copy = reverse(stack_copy)  # reverse the stack to print it in the textarea with appropriate sequence

    # output the result in the form as the example
    print("<div align = \"center\"><h3>M07_servers_and_customers hguo5</h3>")
    print("<table><tr><td>")
    print("<div align = \"center\"> <table>")
    print("<td align='center'>Servers Stack </td>")
    print("<td align='center'>Customers Queue </td>")
    print("<tr><td align='center'><textarea rows='20' cols='20' name='servers'>")
    for i in range(len(stack_copy)):
        print("{} {}".format(stack_copy.top().get_name(), stack_copy.top().get_number()))
        stack_copy.pop()
    print("</textarea></br><font size=\"+2\">Entry/Exit</font></br></td>")

    print("<td align='center'<font size=\"+2\">Exit</font></br><textarea rows='20' cols='20' name='servers'>")
    for i in range(len(queue_copy)):
        print("{} {}".format(queue_copy.first().get_name(), queue_copy.first().get_number()))
        queue_copy.dequeue()
    print("</textarea></br><font size=\"+2\">Entry</font></br></td>")
    print("<tr align='center'><td></td><td><td></td></tr>")
    print("</table></div><td>")
    print("<table bgcolor='antiquewhite' border='2' width='200%'\
             align='center'><tr><th>Servers and Customers</th></tr>")
    open_for_evening(servers_stack, customers_queue)
    print("</td></tr></table>")
