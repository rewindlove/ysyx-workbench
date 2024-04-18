module ysyx_23060278_top(
	input clk,
	input rst,
	input [31:0]inst,
	input pc_wen,
	input [2:0]aluctl,
	input [6:0]opcode,
	input Regwrite,
	output [31:0]result,
	output [31:0]dnxt_pc,
	output [31:0]snxt_pc,
	output wire [31:0]pc
);

	wire [31:0]imm;
	wire [2:0]func3;
	wire [6:0]func7;
	wire [4:0]rs1;
	wire [4:0]rs2;
	wire [4:0]rd;
	wire [31:0]rd_data1;
	wire [31:0]rd_data2;

	wire overflow;
	wire zf;
	wire nf;
	wire cf;

	ysyx_23060278_pc_reg pc_reg(
		.clk(clk),
		.rst(rst),
		.pc_wen(1'b1),
		.dnxt_pc(dnxt_pc),
		.snxt_pc(snxt_pc),
		.pc(pc)
	);

	ysyx_23060278_decoder decoder(
		.inst(inst),
		.opcode(opcode),
		.func3(func3),
		.func7(func7),
		.rs1(rs1),
		.rs2(rs2),
		.rd(rd),
		.imm(imm)
	);

	ysyx_23060278_gpr gpr(
		.clk(clk),
		.rst(rst),
		.w_en(Regwrite),
		.rs1(rs1),
		.rs2(rs1),
		.rd(rd),
		.w_data(result),
		.imm(imm),
		.rd_data1(rd_data1),
		.rd_data2(rd_data2)
	);

	ysyx_23060278_idu idu(
		.idu_inst(inst),
		.idu_opcode(opcode),
		.f3(func3),
		.f7(func7),
		.aluctl(aluctl),
		.Regwrite(Regwrite)
	);

	ysyx_23060278_alu alu(
		.a(rd_data1),
		.b(imm),	//目前只实现addi指令
		.aluctl(aluctl),
		.result(result),
		.overflow(overflow),
		.zf(zf),
		.nf(nf),
		.cf(cf)
		);

endmodule




	
