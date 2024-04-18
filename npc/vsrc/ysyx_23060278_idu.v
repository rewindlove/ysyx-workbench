module ysyx_23060278_idu(
	input [31:0]idu_inst,
	input [6:0]idu_opcode,
	input [2:0]f3,
	input [6:0]f7,
	output [2:0]aluctl,
	output Regwrite
);

	assign aluctl = 3'b000;
	assign Regwrite = 1;


endmodule
