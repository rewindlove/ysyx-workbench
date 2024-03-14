module top(
		input clk,
		input rst,
		input [11:0]sw,
		output [3:0]sum0,
		output [3:0]cout0,
		output [3:0]res0,
		output overflow0,
		output rest0,
		output [7:0]seg0,
		output [7:0]seg1,
		output [7:0]seg2,
		output [7:0]seg3,
		output [7:0]seg4,
		output [7:0]seg5,
		output [7:0]seg6,
		output [7:0]seg7
);

	add add(
			.clk(clk),
			.rst(rst),
			.sw(sw),
			.sum0(sum0),
			.cout0(cout0),
			.overflow0(overflow0)
	);

	lc lc(
			.clk(clk),
			.rst(rst),
			.sw(sw),
			.res0(res0)
	);

	cmp cmp(
			.clk(clk),
			.rst(rst),
			.sw(sw),
			.rest0(rest0)
	);

	seg seg(
			.clk(clk),
			.rst(rst),
			.sw(sw),
			.sum0(sum0),
			.cout0(cout0),
			.overflow0(overflow0),
			.res0(res0),
			.rest0(rest0),
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
