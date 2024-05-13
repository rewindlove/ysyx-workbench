module ysyx_23060278_regfile(
	input clk,
	input rst,
	input w_en,
	input [4:0]rs1,
	input [4:0]rs2,
	input [4:0]rd,
	input [31:0]imm,
	input w_imm,
	input w_pc,
	input w_alu,
	input [31:0]result,	//alu_result
	input [31:0]pc_result,	//pc add 4,传入snxt_pc
	output [31:0]rd_data1,
	output [31:0]rd_data2
);

	wire [31:0]w_data;

	assign w_data = ({32{w_pc }}  & pc_result) |
									({32{w_alu}}  & result)		|
									({32{w_imm}}  & imm);

	reg [31:0] regs [31:0];

	integer i;

//write
	always@(posedge clk)	begin
		if(rst)	begin
			for(i = 0; i < 32; i++)	begin
				regs[i] <= 32'h00000000;		//reset
			end
		end
		else if(w_en & (rd!=0))	begin
			regs[rd] <= w_data;	
		end
	end

//read
	assign rd_data1 = (rs1 == 5'd0) ? 32'd0 : regs[rs1];	//0号寄存器值恒为0
	assign rd_data2 = (rs2 == 5'd0) ? 32'd0 : regs[rs2];

endmodule
