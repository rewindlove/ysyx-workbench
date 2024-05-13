module ysyx_23060278_mux2_1(
	input [31:0]a,
	input [31:0]b,
	input sel,
	output [31:0]opdata
	
);

	ysyx_23060278_MuxKey #(2, 1, 32) mux2_1 (opdata, sel,{
		1'b0, a,
		1'b1, b
		});

endmodule
