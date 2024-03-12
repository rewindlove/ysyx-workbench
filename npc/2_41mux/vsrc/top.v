module top(
		input clk,
		input rst,
		input [9:0]sw,
		output [1:0]f,
		output [7:0]seg0,
		output [7:0]seg1,
		output [7:0]seg2,
		output [7:0]seg3,
		output [7:0]seg4,
		output [7:0]seg5,
		output [7:0]seg6,
		output [7:0]seg7
);
	sw1 sw1(
					.clk(clk),
					.rst(rst),
					.sw(sw),
					.f(f)
	);
	seg seg(
					.clk(clk),
					.rst(rst),
					.f(f),
					.seg0(seg0),
					.seg1(seg1),
					.seg2(seg2),
					.seg3(seg3),
					.seg4(seg4),
					.seg5(seg5),
					.seg6(seg6),
					.seg7(seg7)
	);
	endmodule
