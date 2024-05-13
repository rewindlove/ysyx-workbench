module ysyx_23060278_pc_reg(
		input clk,
		input rst,
		input pc_wen,
		input jal_en,
		input jalr_en,
		input [31:0]result,
		output [31:0]dnxt_pc,
		output [31:0]snxt_pc,
		output reg [31:0]pc
);

	wire [31:0]jal_pc = result;
	wire [31:0]jalr_pc = result & {{31{1'b1}}, 1'b0};	//跳转地址最低位清零

	wire snxt_en = (!jal_en) & (!jalr_en);	

	assign snxt_pc = pc + 4;
	
	assign dnxt_pc = ({32{snxt_en}} & snxt_pc) |
									 ({32{jal_en }} & jal_pc ) |
									 ({32{jalr_en}} & jalr_pc);

	always @(posedge clk)	begin
			if(rst)	begin
				pc <= 32'h80000000;	//reset
			end
			else if(pc_wen)	begin
				pc <= dnxt_pc;
			end
	end

		
endmodule
