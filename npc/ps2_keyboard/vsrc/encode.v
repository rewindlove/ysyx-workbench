module encode(
				input clk,
				input rst,
				input [8:0]sw,
				output [2:0]y
);
		reg [2:0]y0;
		always @ (posedge clk)	begin
						if(sw[8]==1)	begin
						casez(sw[7:0])
										8'b00000001:y0=3'b000;
										8'b0000001?:y0=3'b001;
										8'b000001??:y0=3'b010;
										8'b00001???:y0=3'b011;
										8'b0001????:y0=3'b100;
										8'b001?????:y0=3'b101;
										8'b01??????:y0=3'b110;
										8'b1???????:y0=3'b111;
										default:y0=3'b000;
						endcase
					end
		end
		assign y=y0;
endmodule
