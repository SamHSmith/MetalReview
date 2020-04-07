use std::ffi::{CStr, CString};
use libc::c_char;

#[link(kind = "dylib", name = "gtkwin")]
extern "C" {

    fn gtk_set_title(title: &CStr);

    fn gtk_set_size(width: i32, height: i32);

    fn is_close_button_pressed() -> i32;

    fn gtk_refresh_window();

    fn gtk_show_window();

    fn gtk_hide_window();

    fn gtk_create_window();

    fn gtk_create_window_and_show(width: i32, height: i32, title: *const c_char);

    fn gtk_init_gtk();
}

fn main() {
    unsafe {
        gtk_init_gtk();
        gtk_create_window_and_show(
            640,
            480,
            CString::new("Look this is rust").unwrap().as_c_str().as_ptr(),
        );

        while(is_close_button_pressed()==0){
            gtk_refresh_window();
        }
    }
    println!("Hello, world!");
}
