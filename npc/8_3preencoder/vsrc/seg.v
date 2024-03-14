module seg(
	input clk,
	input rst,
	input [2:0]y,
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
			for(i=0;i<4;i++)	begin
							if(y[i]==0)
											segs[i]=8'b00000011;
							else
											segs[i]=8'b10011111;
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
