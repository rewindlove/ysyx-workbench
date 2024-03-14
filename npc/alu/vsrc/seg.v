module seg(
	input clk,
	input rst,
	input [11:0]sw,
	input [3:0]sum0,
	input [3:0]cout0,
	input overflow0,
	input [3:0]res0,
	input rest0,
	output [7:0]seg0,
	output [7:0]seg1,
	output [7:0]seg2,
	output [7:0]seg3,
	output [7:0]seg4,
	output [7:0]seg5,
	output [7:0]seg6,
	output [7:0]seg7

);

	integer i;
	wire en;
	assign en=sw[11];
	reg [7:0] segs [7:0];
	always @ (posedge clk) begin
			segs[0]=8'b11111111;
			segs[1]=8'b11111111;
			segs[2]=8'b11111111;
			segs[3]=8'b11111111;
			segs[4]=8'b11111111;
			segs[5]=8'b11111111;
			segs[6]=8'b11111111;
			segs[7]=8'b11111111;
			if(en)	begin
			if(sw[10:8]==3'b000||sw[10:8]==3'b001)	begin
					for(i=0;i<4;i++)	begin
							if(sum0[i]==0)
								segs[i]=8'b00000011;
							else
								segs[i]=8'b10011111;
					end
					if(cout0[3]==0)
						segs[4]=8'b00000011;
					else
						segs[4]=8'b10011111;
					if(overflow0==0)
						segs[5]=8'b00000011;
					else
						segs[5]=8'b10011111;
			end
			if(sw[10:8]==3'b010||sw[10:8]==3'b011||sw[10:8]==3'b100||sw[10:8]==3'b101)	begin
					for(i=0;i<4;i++)	begin
							if(res0[i]==0)
								segs[i]=8'b00000011;
							else
								segs[i]=8'b10011111;
					end
			end
			if(sw[10:8]==3'b110||sw[10:8]==3'b111)	begin
					if(rest0==0)
							segs[0]=8'b00000011;
					else
							segs[0]=8'b10011111;
			end
	end
	end
	assign seg0=segs[0];
	assign seg1=segs[1];
	assign seg2=segs[2];
	assign seg3=segs[3];
	assign seg4=segs[4];
	assign seg5=segs[5];
	assign seg6=segs[6];
	assign seg7=segs[7];
endmodule
