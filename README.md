## Introduction

    This is my project for Algoritmos e Estruturas de Dados 2(Algorithms and Data structures 2).
    The problem was to make an auto parking system.

## Adopted Strategy

To successfully make the project first we had to make some decicions.

#### The first problem to resolve was which data structure to use ?

    In this topic i choosed to use linked list over hash table due to the simplicity of the problem. 
    The Arrays were another option but it wasn't show nothing that we learned during the classes.
    And with array we get on average:
    - Acess: O(1)
    - Search: O(n)
    - Insertion: O(n)
    - Deletion: O(n)

    With the linked list we get on average:
    - Acess: O(n)
    - Search: O(n)
    - Insertion: O(1)
    - Deletion: O(1)

    With the hash map we get on average:
    - Acess:
    - Search: O(1)
    - Insertion: O(1)
    - Deletion: O(1)

    For linked list we get a nice combo of simplicity to implement and time and space complexity(the complexity is equal for the 3).
    With this and a little bit of pointer studying i manage to implement the linked list.

## Implementations

#### The start

    When you start the program for the first time it's going to ask for the number of pisos, linhas, colunas and price(floors, rows, columns and price) of the park.

    If you already started the program one time, the information will be gathered from the "estruturaParque.csv" file.


#### First Option

    Shows how the occupied and free spots in the park.

#### Second Option

    We have to put the car in the park so we ask the registration(plate) and model of the car.
    The next step is to choose the spot of the car and we give 2 options:
    - Choose the nearest free spot
    - CHoose the spor manually

#### Third Option
    
    In this option we check if in a given spot has a car or not and if th spot isn't occupied show the car plate of the car.

#### Fourth Option

    We have to remove the car when the owner wants to. So it's what we make in this option.
    

## Run Locally

Clone the project

```bash
  git clone https://github.com/Franciscoborges2002/autoParkingC.git
```

Compile the files

And finaly just run 'main.exe'.


## License

[MIT](https://choosealicense.com/licenses/mit/)

  