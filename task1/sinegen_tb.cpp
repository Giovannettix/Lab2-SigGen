#include"Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <windows.h>

int main(int argc, char **argv, char **env){
    int i;
    int clk;
    int keyCode;

    Verilated::commandArgs(argc, argv)
    //init top verilog instance
    Vsinegen* top = new Vsinegen;
    //init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("sinegen.vcd")

    //initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0; 
    top->incr = 1;

    for(i=0; i<100_000_000; i++){

        // dump variables into VCD file and toggle clock
        for(clk=0; clk<2; clk++){
            tfp->dump(2*i+clk);    //unit is in ps
            top->clk = !top->clk;
            top->eval();
        }
        top->rst = (i<2) | (i==15);
        top->en = (i>4);
        if(Verilated::gotFinish()|(GetAsyncKeyState(keyCode)&0x51)) exit(0);
    }
    tfp->close();
    exit(0);
}

