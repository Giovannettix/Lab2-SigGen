module sinegen#(
    parameter   ADDRESS_WIDTH = 8,
    parameter   DATA_WIDTH = 8
)(
    input logic clk,
    input logic en,
    input logic rst,
    input logic [ADDRESS_WIDTH-1:0] incr,
    output logic [DATA_WIDTH-1:0] dout
);

logic [ADDRESS_WIDTH-1:0] addr;

counter #(ADDRESS_WIDTH) c1(
    .clk(clk), 
    .en(en), 
    .rst(rst), 
    .count(addr), .incr(incr));

rom #(ADDRESS_WIDTH, DATA_WIDTH) rom1(
    .clk(clk),
    .addr(addr),
    .dout(dout)
);

endmodule 
