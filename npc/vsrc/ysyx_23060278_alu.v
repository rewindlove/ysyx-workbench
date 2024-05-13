module ysyx_23060278_alu(
	input [31:0]opdata1,
	input [31:0]opdata2,
	input [2:0]aluctl,
	output [31:0]result
);

	wire [31:0]add_result;
	wire [31:0]andres;
	wire [31:0]orres;

	assign add_result = opdata1 + opdata2;
	assign     andres = opdata1 & opdata2;
	assign      orres = opdata1 | opdata2;

	ysyx_23060278_MuxKey #(4, 3, 32)	alumux(result, aluctl, {
		3'b000, add_result,
		3'b001, add_result,
		3'b010, andres,
		3'b011, orres
	});


endmodule
