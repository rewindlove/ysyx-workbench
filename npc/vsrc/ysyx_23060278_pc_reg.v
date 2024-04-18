module ysyx_23060278_pc_reg(
		input clk,
		input rst,
		input pc_wen,
		output [31:0]dnxt_pc,
		output [31:0]snxt_pc,
		output reg [31:0]pc
);
	//位宽为32bit，复位值为0x80000000,写使能为w_en
	//Reg #(32,8'h80000000) pc_reg (clk, rst, nextpc[31:0], pc[31:0],w_en);
	wire snxt_en = 1;	//暂时还没有其他信号，直接赋值为1
	assign snxt_pc = pc + 4;
	
	assign dnxt_pc = {{32{snxt_en}} & snxt_pc};

	always @(posedge clk)	begin
			if(rst)	begin
				pc <= 32'h80000000;	//reset
			end
			else if(pc_wen)	begin
				pc <= dnxt_pc;
			end
	end

		
endmodule
