module ysyx_23060278_idu(
	input [31:0]idu_inst,
	input [6:0]idu_opcode,
	input [2:0]f3,
	input [6:0]f7,
	output [2:0]aluctl,
	output alusrc,
	output regwrite,
	output auipc_en,
	output jal_en,
	output jalr_en,
	output lui_en,
	output w_pc,
	output w_imm,		//写回imm，用于lui指令，目前没想到更好的办法，所以先这样处理了
	output w_alu
);

	wire R_type;
	wire I_type;
	wire U_type;

	assign auipc_en = (idu_opcode == 7'b0010111);
	assign jal_en   = (idu_opcode == 7'b1101111);
	assign jalr_en  = (idu_opcode == 7'b1100111);
	assign lui_en   = (idu_opcode == 7'b0110111);

	assign I_type   = (idu_opcode == 7'b0010011);
	assign R_type   = (idu_opcode == 7'b0110011);
	assign U_type   = (lui_en | auipc_en);

	assign alusrc   = U_type | jalr_en | jal_en;	//select pc
	assign regwrite = jal_en | jalr_en | I_type | R_type | U_type;

	assign aluctl = (auipc_en | jal_en | jalr_en | lui_en) ? 000 : 001;
	
	//写回控制信号
	assign w_pc  = jal_en | jalr_en;
	assign w_alu = auipc_en;
	assign w_imm = lui_en;

	


endmodule
