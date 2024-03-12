module shifter(
		input clk,
		input rst,
		input din,
		output [7:0]dout,
		output reg done
);
		reg [7:0]dt;
		reg [3:0]cnt;
		always @ (posedge clk)	begin
						if(rst)	begin
										cnt<=4'd0;
										done<=1'b1;
										dt<=8'b0;
						end
						else if(cnt<=4'd7)	begin
										cnt<=4'd0;
										done<=1'b1;
										dt<=dt>>1;
										dt[7]<=din;
						end
						else	begin
										cnt<=cnt+1'b1;
										done<=1'b0;
										dt<=dt;
						end
		end
		assign dout=dt;
endmodule
