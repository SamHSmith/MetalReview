
mod native{
    use std::ffi::{CString};
    use libc::c_char;

    #[link(kind = "dylib", name = "gtkwin")]
    extern "C" {

        fn gtk_set_title(title: *const c_char);

        fn gtk_set_size(width: i32, height: i32);

        fn is_close_button_pressed() -> i32;

        fn gtk_refresh_window();

        fn gtk_show_window();

        fn gtk_hide_window();

        fn gtk_create_window();

        fn gtk_create_window_and_show(width: i32, height: i32, title: *const c_char);

        fn gtk_init_gtk();
    }

    pub fn window_should_close() -> bool{
        unsafe { is_close_button_pressed() != 0 }
    }

    //resets should close
    pub fn window_refresh(){
        unsafe { gtk_refresh_window(); }
    }



    pub fn create_window_and_show(width: i32, height: i32, title: &str){
        let cstr=CString::new(title).unwrap();
        unsafe { gtk_create_window_and_show(width, height, cstr.as_ptr()); }
    }

    pub fn window_init(){ unsafe {gtk_init_gtk();} }
}

use native::*;

fn main() {
    unsafe {
        window_init();
        create_window_and_show(
            640,
            480,
            "Haha, this window is \"safe\"",
        );

        while !window_should_close() {
            window_refresh();
        }
    }
    println!("Hello, world!");
}
