import unittest
import math
from heapq import heappush, heappop

def min_transfers(debt):
    deudores = []
    acreedores = []
    personas = {}
    for lista in range(len(debt)):
        personas[lista] = 0
    
    for fila in range(len(debt)):
        for columna in range(len(debt[fila])):
            personas[fila] -= debt[fila][columna]
            personas[columna] += debt[fila][columna]
    

    for persona in personas:
        if personas[persona] < 0:
            deudores += [[persona, personas[persona]]] # que persona es, deuda
        if personas[persona] > 0:
            acreedores += [[persona, personas[persona]]]

    deudores.sort()
    acreedores.sort()

    i, j = 0, 0
    while i < len(deudores) and j < len(acreedores):
        print(f'holaa {acreedores}, a {deudores}')
        acreedores[j][1] += deudores[i][1]
        deudores[i][1] -= (deudores[i][1])

        if(deudores[i][1] == 0):
            i += 1
        if(acreedores[j][1] == 0):
            j += 1
        

            




import unittest

class TestSimplifyDebtsGreedy(unittest.TestCase):
    def test_case_1(self):
        debt = [
            [0, 10, 0],
            [0, 0, 5],
            [7, 0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 2)
        self.assertEqual(result, [(0,1,3), (2,1,2)])


    def test_case_balanced(self):
        debt = [
            [0, 5],
            [5, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 0)
        self.assertEqual(result, [])

    def test_no_debt(self):
        debt = [
            [0, 0],
            [0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(result, [])

    def test_chain(self):
        debt = [
            [0, 5, 0],
            [0, 0, 5],
            [0, 0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 1)
        self.assertEqual(result, [(0,2,5)])


if __name__ == '__main__':
    unittest.main()
