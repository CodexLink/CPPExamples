const RawHTML = {
	data() {
		return {
			dynamicFunction_Receive: null,
			dynamicId: 12,
			dynamicptr: "click",
			githubUrl: "https://github.com/CodexLink/CodexLink",
			isButtonDisabled: true,
			rawHtml: '<span style="color: red"> This should be red.</span>'
		}
	},
	methods: {
		changeButtonState() {
			this.isButtonDisabled = !this.isButtonDisabled
		},
		dynamicFunction() {
			this.dynamicFunction_Receive = this.dynamicptr
		}
	}
}

Vue.createApp(RawHTML).mount("#example1")