#ifndef __XUD_CDC_H__
#define __XUD_CDC_H__

interface usb_cdc_interface {
	[[guarded]] void put_char(char byte);
	[[guarded]] char get_char(void);
	[[guarded]] int write(unsigned char data[], REFERENCE_PARAM(unsigned, length));
	[[guarded]] int read(unsigned char data[], REFERENCE_PARAM(unsigned, count));
	int available_bytes(void);
	void flush_buffer(void);
};

void Endpoint0(chanend chan_ep0_out, chanend chan_ep0_in);
void CdcEndpointsHandler(chanend c_epint_in, chanend c_epbulk_out, chanend c_epbulk_in, server interface usb_cdc_interface cdc);

#endif /* __XUD_CDC_H__ */

