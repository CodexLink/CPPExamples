const clsLoader = Vue.createApp({
	data() {
		return {
			shouldRender: true,
			isElementActive: true,
			// Some side effect for statements in computed property.
			isDataLoaded: true,
			renderDone: true,
		}
	},
	computed: {
		init_cls() {
			return {
				// Basically, cls to invoke: conditional statement.
				rendered: this.isDataLoaded && this.isElementActive,
				elementActivated: this.renderDone && !this.fshouldRender
			}
		}
	}
}).mount("#cls_example")