module lc(
	input clk,
	input rst,
	input [11:0]sw,
	output [3:0]res0
);

	wire [3:0]a,b;
	wire en;
	reg [3:0]res;
	assign a=sw[3:0];
	assign b=sw[7:4];
	assign en=sw[11];
	always @ (posedge clk)	begin
		if(en)	begin
			case(sw[10:8])
					3'b010:res=~a;
					3'b011:res=a&b;
					3'b100:res=a|b;
					3'b101:res=a^b;
					default:res=4'b0000;
			endcase
	end
	end
	assign res0=res;
endmodule
