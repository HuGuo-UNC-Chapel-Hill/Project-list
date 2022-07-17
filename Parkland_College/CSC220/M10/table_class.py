from exceptions import Empty


table={}
class Table(**table):
    def __init__(self):
        self._data = table
        
    def _add_value(self, left, right):
        self._data[left] = float(right)
        
    def _update_value(self, left, right):
        self._data[left] = self._data[right]
    
    def _error(self, value):
        raise NotImplementedError("Error: {} not defined".format(value))
        
    def get_value(self, value):
        if value not in self._data:
            self._error(value)
        else:
            return self._data[value]    
   
    def manipulation(self, left, right):
        if right in self._data or right[0].isdigit():
            if left[0] == "v" and right[0].isdigit():
                self._add_value(left, right)
            elif left[0] == "v" and not right[0].isdigit():
                self._update_value(left, right)
        else:
            self._error(right)
            
    def output(self):
        for i in list(self._data.keys()):
            print("<tr align='center'><td>{} := {} </td></tr>"
                    .format(i, self.get_value(i)))
            
       
if __name__ == '__main__':
    test = Table()
    test.output_table()
    test.manipulation("var1", "23.5")
    test.manipulation("var2", "var1")
    test.manipulation("var2", "var9")
    test.output_table()
