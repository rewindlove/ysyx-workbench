module ysyx_23060278_top(
	input clk,
	input rst,
	input [31:0]inst,
	output [31:0]dnxt_pc,
	output [31:0]snxt_pc,
	output wire [31:0]pc
);

	wire [31:0]imm;
	wire [6:0]opcode;
	wire [2:0]func3;
	wire [6:0]func7;
	wire [4:0]rs1;
	wire [4:0]rs2;
	wire [4:0]rd;

	wire [31:0]rd_data1;
	wire [31:0]rd_data2;
	wire [31:0]alu_data1;

	wire [31:0]result;	//add result
	

	wire [2:0]aluctl;
	wire alusrc;
	wire regwrite;

	wire auipc_en;
	wire jal_en;
	wire jalr_en;
	wire lui_en;

	wire w_pc;
	wire w_alu;
	wire w_imm;



	ysyx_23060278_pc_reg pc_reg(
		.clk(clk),
		.rst(rst),
		.pc_wen(1'b1),
		.jal_en(jal_en),
		.jalr_en(jalr_en),
		.result(result),
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

	ysyx_23060278_regfile regfile(
		.clk(clk),
		.rst(rst),
		.w_en(regwrite),
		.rs1(rs1),
		.rs2(rs2),
		.rd(rd),
		.imm(imm),
		.w_imm(w_imm),
		.w_pc(w_pc),
		.w_alu(w_alu),
		.result(result),
		.pc_result(snxt_pc),
		.rd_data1(rd_data1),
		.rd_data2(rd_data2)
	);

	ysyx_23060278_idu idu(
		.idu_inst(inst),
		.idu_opcode(opcode),
		.f3(func3),
		.f7(func7),
		.aluctl(aluctl),
		.alusrc(alusrc),
		.regwrite(regwrite),
		.auipc_en(auipc_en),
		.jal_en(jal_en),
		.jalr_en(jalr_en),
		.lui_en(lui_en),
		.w_pc(w_pc),
		.w_imm(w_imm),
		.w_alu(w_alu)
	);

	ysyx_23060278_mux2_1 alu_data1_mux(
		.a(rd_data1),
		.b(pc),
		.sel(alusrc),
		.opdata(alu_data1)
	);

	ysyx_23060278_alu alu(
		.opdata1(alu_data1),
		.opdata2(imm),	//目前只实现addi指令
		.aluctl(aluctl),
		.result(result)
		);

endmodule




	
