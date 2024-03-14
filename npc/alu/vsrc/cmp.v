module cmp(
	input clk,
	input rst,
	input [11:0]sw,
	output reg rest0
);

	wire [3:0]a,b;
	wire en;
	reg rest;
	assign a=sw[3:0];
	assign b=sw[7:4];
	assign en=sw[11];
	always @ (posedge clk)	begin
		if(en)	begin
			case(sw[10:8])
					3'b110:rest=(a>b)? 0:1;
					3'b111:rest=(a==b)? 1:0;
					default:rest=1'b0;
			endcase
	end
	end 
	assign rest0=rest;
endmodule
