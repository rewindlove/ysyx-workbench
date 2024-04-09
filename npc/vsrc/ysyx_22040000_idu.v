module ysyx_22040000_idu(
	input [6:0]opcode,
	input [2:0]f3,
	input [6:0]f7,
	output [2:0]aluctl,
	output Regwrite,
	output [2:0]immtype
);

	assign aluctl = 3'b000;
	assign Regwrite = 1;
	assign immtype = 3'b000;

endmodule
