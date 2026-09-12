# IAS Simulator

class CPU:
    def __init__(self, busRAM):
        self.clockIsPowered = True

        ## Bus
        self.RAM = busRAM

        ## PC
        self.PC  = None  # Program Counter

        ## Register File
        self.AC  = 0     # Accumulator                 - results of + or -
        self.MAR = None  # Memory Address Register     - address in RAM
        self.MBR = None  # Memory Buffer Register      - data retrieved from RAM
        self.IR  = None  # Instruction Register        - current instruction
        self.IBR = None  # Instruction Buffer Register - next instruction

        ## ALU
        def add():  self.AC            += self.MBR
        def div():  self.AC            /= self.MBR
        def load(): self.AC             = self.MBR
        def stor(): self.RAM[self.MAR]  = self.AC
        def sub():  self.AC            -= self.MBR
        def halt(): self.clockIsPowered = False

        ## Instruction Set
        self.InstructionSet = {
            "ADD":  add,  "DIV": div, "LOAD": load,
            "STOR": stor, "SUB": sub, "HALT": halt
        }
    
    def fetch(self):
        ## IAS would crash if word was not completely filled
        ## Can use dummy instruction (like adding 0 to AC)
        if self.IBR is None:
            ## get new word
            self.MAR = self.PC
            self.MBR = self.RAM[self.MAR]
            self.IR, self.IBR = self.MBR
        else:
            ## move instruction from buffer to IR
            self.IR = self.IBR
            self.IBR = None
            self.PC += 1

    def decode_execute(self):
        # decode
        opcode, address = self.IR
        self.MAR = address
        if self.MAR is not None:
            self.MBR = self.RAM[self.MAR]

        # execute
        self.InstructionSet[opcode]()
        self.IR = None


## They used punch cards or telegram paper or whatever
PUNCH_CARD_LIB = {
    "partC": [
        4,
        7,
        2,
        0,
        (("LOAD", 0),    ("SUB" , 1)),
        (("DIV" , 2),    ("STOR", 3)),
        (("HALT", None), None)
    ],

    "partD": [
        4,
        8,
        13,
        0,
        (("LOAD", 0),  ("ADD" , 1)),
        (("ADD" , 2),  ("STOR", 3)),
        (("HALT", None), None)
    ]
}


class IAS():
    def __init__(self):
        self.memory = {
        # address: value
            0:  4323,  1:  None,  2:  "asfklsd",
            3:  None,  4:  23.9,  5:  'c',
            6:  2332,  7:  -9,    8:  "asdlf",
            9:  None,  10: None,  11: True
        }
        self.CPU = CPU(self.memory)

    def runProgram(self, program, PC=0):
        # load program into primary memory
        for index, word in enumerate(program):
            self.memory[index] = word
        # initialize Program Counter to desired value
        self.CPU.PC = PC
        while (self.CPU.clockIsPowered):
            self.CPU.fetch()
            self.CPU.decode_execute()


def main():
    myComputer = IAS()
    myComputer.runProgram(PUNCH_CARD_LIB["partC"], PC=4)
    print(f"(4 - 7) / 2 = {myComputer.memory[3]}")

    myComputer.CPU.clockIsPowered = True
    myComputer.runProgram(PUNCH_CARD_LIB["partD"], PC=4)
    print(f"4 + 8 + 13 = {myComputer.memory[3]}")



if __name__ == "__main__":
    main()