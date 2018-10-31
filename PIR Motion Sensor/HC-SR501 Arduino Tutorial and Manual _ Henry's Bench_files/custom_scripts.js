(function($) {
	$(document).ready(function(){
		
		// Show/Hide search bar in Mobile menu
		$(".mobile_search").hide();
		$(".searchtoggle").click(function(){
			$(".mobile_search").slideToggle('slow');
		});
		
		$('.search-bar .search-field').focus(function () {
			$(this).animate({ width: "150px" }, 500);
		});
		$('.search-bar .search-field').focusout(function () {
			$(this).animate({ width: "90px" }, 500);
		});

		/* Top Menu */

		// Populate dropdown with menu items
		$("#top-menu a").each(function() {
			var el = $(this);
			$("<option />", {
				"value"   : el.attr("href"),
				"text"    : el.text()
			}).appendTo("#top-menu select");
		});
		
		// To make the dropdown menu actually work!
		$("#top-menu select").change(function() {
		  window.location = $(this).find("option:selected").val();
		});
	});
})(jQuery);

// Slidebars
(function($) {
	$(document).ready(function() {
		$.slidebars();
	});
}) (jQuery);

// Menu Accordion
( function( $ ) {
$( document ).ready(function() {
$('.mobile-menu-wrap li.has-sub>a').on('click', function(){
		$(this).removeAttr('href');
		var element = $(this).parent('li');
		if (element.hasClass('open')) {
			element.removeClass('open');
			element.find('li').removeClass('open');
			element.find('ul').slideUp();
		}
		else {
			element.addClass('open');
			element.children('ul').slideDown();
			element.siblings('li').children('ul').slideUp();
			element.siblings('li').removeClass('open');
			element.siblings('li').find('li').removeClass('open');
			element.siblings('li').find('ul').slideUp();
		}
	});
});
} )( jQuery );