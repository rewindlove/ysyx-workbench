module ysyx_22040000_alu(
	input [31:0]a,
	input [31:0]b,
	input [2:0]aluctl,
	output [31:0]result,
	output overflow,
	output zf,
	output nf,
	output cf
);

	wire [31:0]addres;
	wire [31:0]andres;
	wire [31:0]orres;
	wire [31:0]b2;

	assign b2 = b ^ {32{aluctl[0]}};
	assign {cf,addres} = a + b2 + aluctl[0];
	assign overflow = (~ (a[31] ^ b2[31])) & (a[31] ^ addres[31]);
	assign andres = a & b;
	assign orres = a | b;

	ysyx_22040000_MuxKey #(4, 3, 32)	alumux(result, aluctl, {
		3'b000, addres;
		3'b001, addres;
		3'b010, andres;
		3'b011, orres;
	});

	assign zf = ~(|result);
	assign nf = result[31];

endmodule
