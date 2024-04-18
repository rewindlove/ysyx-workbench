module ysyx_23060278_alu(
	input [31:0]a,
	input [31:0]b,
	input [2:0]aluctl,
	output [31:0]result,
	output overflow,
	output zf,
	output nf,
	output cf
);

	wire [31:0]add_result;
	wire [31:0]andres;
	wire [31:0]orres;
	wire [31:0]b2;
	wire

	assign b2 = b ^ {32{aluctl[0]}};
	assign {cf,add_result} = a + b2 + aluctl[0];
	assign overflow = (~ (a[31] ^ b2[31])) & (a[31] ^ add_result[31]);
	assign andres = a & b;
	assign orres = a | b;

	ysyx_23060278_MuxKey #(4, 3, 32)	alumux(result, aluctl, {
		3'b000, add_result;
		3'b001, add_result;
		3'b010, andres;
		3'b011, orres;
	});

	assign zf = ~(|result);
	assign nf = result[31];

endmodule
